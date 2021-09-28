pub struct SegTree<T, Op> {
	segt: Vec<T>,
	n: usize,
	op: Op,
	e: T,
}

impl<T, Op> SegTree<T, Op>
where
	T: Copy,
	Op: Fn(T, T) -> T,
{
	
	fn left(si: usize) -> usize {
		return si * 2;
	}
	fn right(si: usize) -> usize {
		return si * 2 + 1;
	}
	fn getMid(ss: usize, se: usize) -> usize {
		return ss + (se - ss) / 2;
	}
	
	
	fn query(&self,ss: usize, se: usize, qs: usize, qe: usize, si: usize) -> T
	{
		if se < qs || qe < ss {
			self.e
		}
		else 
		if qs <= ss && qe >= se {
			self.segt[si]
		}
		else {
			let mid = self.getMid(ss, se);
			
			return op(query(ss, mid, qs, qe, left(si)), query(mid + 1, se, qs, qe, right(si)));
		}
	}
	
	void update(int ss, int se, int key, int si)
	{
		if (ss == se)
		{
			segt[si] = a[ss];
			return;
		}
		
		int mid = getMid(ss, se);
		
		if (key > mid)
		update(mid + 1, se, key, right(si));
		else
		update(ss, mid, key, left(si));
		
		segt[si] = op(segt[left(si)], segt[right(si)]);
	}
	
	pub fn new(arr: &Vec<T>, op: Op, init: T) -> SegTree<T, Op> {
		let curr = SegTree {
			seg: vec![init; arr.len()],
			n: arr.len(),
			op,
			init,
		};

		for i in 0..arr.len() {
			curr.set(i, arr[i]);
		}

		return curr;
	}
	T get(int qs, int qe)
	{
		return query(0, n - 1, qs, qe, 1);
	}
	
	void set(int key, T val)
	{
		a[key] = val;
		update(0, n - 1, key, 1);
	}
}

#[cfg(test)]
mod test {
	use super::*;
	use rand::Rng;
	use std::cmp;

	const INF: i64 = 1 << 60;

	#[test]
	fn random_array() {
		let n = 1000;
		let arr = (0..n)
			.map(|_| {
				return rand::thread_rng().gen::<i64>();
			})
			.collect::<Vec<_>>();

		let mut seg = SegTree::new(n, |a, b| cmp::min(a, b), INF);
		for i in 0..n {
			let mut minimum = INF;
			for j in 0..(i + 1) {
				minimum = cmp::min(minimum, arr[j]);
			}
			seg.update(i, arr[i]);
			assert_eq!(seg.query(0..n), minimum);
			assert_eq!(seg.query(0..(i + 1)), minimum);
		}
	}

	#[test]
	fn random_array_online_update() {
		let n = 1000;

		let mut arr = vec![INF; n];
		let mut seg = SegTree::new(n, |a, b| cmp::min(a, b), || INF);

		for _ in 0..n {
			let value = rand::thread_rng().gen::<i64>();
			let k = rand::thread_rng().gen_range(0, n);
			seg.update(k, value);

			arr[k] = value;
			let mut minimum = INF;
			for i in 0..n {
				minimum = cmp::min(minimum, arr[i]);
			}
			assert_eq!(seg.query(0..n), minimum);
		}
	}
}
