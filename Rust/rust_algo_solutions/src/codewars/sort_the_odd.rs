pub fn sort_array_impl(arr: &[i32]) -> Vec<i32> {
    let source = arr.to_vec();
    let mut odds: Vec<i32> = source
        .clone()
        .into_iter()
        .filter(|val| val % 2 != 0)
        .collect();

    use std::cmp::Ordering;
    odds.sort_by(|first, second| match first.cmp(second) {
        Ordering::Less => Ordering::Greater,
        Ordering::Greater => Ordering::Less,
        Ordering::Equal => Ordering::Equal,
    });

    source
        .into_iter()
        .map(|val| {
            if val % 2 != 0 {
                odds.pop().unwrap()
            } else {
                return val;
            }
        })
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn basic() {
        assert_eq!(sort_array_impl(&[5, 3, 2, 8, 1, 4]), [1, 3, 2, 8, 5, 4]);
        assert_eq!(sort_array_impl(&[5, 3, 1, 8, 0]), [1, 3, 5, 8, 0]);
        assert_eq!(sort_array_impl(&[]), []);
    }
}