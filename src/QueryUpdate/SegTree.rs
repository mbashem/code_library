#[allow(dead_code)]

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
	fn left(&self, si: usize) -> usize {
		return si * 2;
	}
	fn right(&self, si: usize) -> usize {
		return si * 2 + 1;
	}
	fn get_mid(&self, ss: usize, se: usize) -> usize {
		return ss + (se - ss) / 2;
	}

	fn query(&self, ss: usize, se: usize, qs: usize, qe: usize, si: usize) -> T {
		if se < qs || qe < ss {
			self.e
		} else if qs <= ss && qe >= se {
			self.segt[si]
		} else {
			let mid = self.get_mid(ss, se);

			(self.op)(
				self.query(ss, mid, qs, qe, self.left(si)),
				self.query(mid + 1, se, qs, qe, self.right(si)),
			)
		}
	}

	fn update(&mut self, ss: usize, se: usize, key: usize, si: usize, val: T) {
		if ss == se {
			self.segt[si] = val;
			return;
		}
		let mid = self.get_mid(ss, se);
		if key > mid {
			self.update(mid + 1, se, key, self.right(si), val);
		} else {
			self.update(ss, mid, key, self.left(si), val);
		}

		self.segt[si] = (self.op)(self.segt[self.left(si)], self.segt[self.right(si)]);
	}

	pub fn new(arr: &Vec<T>, op: Op, init: T) -> SegTree<T, Op> {
		let mut curr = SegTree::new_len(arr.len(), op, init);

		for i in 0..arr.len() {
			curr.set(i, arr[i]);
		}

		return curr;
	}

	pub fn new_len(n: usize, op: Op, init: T) -> SegTree<T, Op> {
		SegTree {
			segt: vec![init; 4 * n + 5],
			n: n,
			op: op,
			e: init,
		}
	}

	fn get(&self, qs: usize, qe: usize) -> T {
		self.query(0, self.n - 1, qs, qe, 1)
	}

	fn set(&mut self, key: usize, val: T) {
		self.update(0, self.n - 1, key, 1, val);
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

		let mut seg = SegTree::new_len(n, |a, b| cmp::min(a, b), INF);
		for i in 0..n {
			let mut minimum = INF;
			for j in 0..(i + 1) {
				minimum = cmp::min(minimum, arr[j]);
			}
			seg.set(i, arr[i]);
			assert_eq!(seg.get(0, n), minimum);
			assert_eq!(seg.get(0, i + 1), minimum);
		}
	}

	#[test]
	fn random_array_online_update() {
		let n = 1000;

		let mut arr = vec![INF; n];
		let mut seg = SegTree::new_len(n, |a, b| cmp::min(a, b), INF);

		for _ in 0..n {
			let value = rand::thread_rng().gen::<i64>();
			let k = rand::thread_rng().gen_range(0..n);
			seg.set(k, value);

			arr[k] = value;
			let mut minimum = INF;
			for i in 0..n {
				minimum = cmp::min(minimum, arr[i]);
			}
			assert_eq!(seg.get(0, n), minimum);
		}
	}
}
