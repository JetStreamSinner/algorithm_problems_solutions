pub fn unique_in_order_impl<T>(sequence: T) -> Vec<T::Item>
where
    T: std::iter::IntoIterator,
    T::Item: std::cmp::PartialEq + std::fmt::Debug,
{
    let mut input: Vec<T::Item> = sequence.into_iter().collect();
    input.dedup();
    input
}

#[cfg(test)]
mod unique_in_order_test {
    use super::*;

    #[test]
    fn sample_test() {
        assert_eq!(
            unique_in_order_impl("AAAABBBCCDAABBB".chars()),
            vec!['A', 'B', 'C', 'D', 'A', 'B']
        );
    }
}
