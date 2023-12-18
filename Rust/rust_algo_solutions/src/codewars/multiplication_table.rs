pub fn multiplication_table_impl(len: usize) -> Vec<Vec<usize>> {
    (1..len + 1)
        .map(|row_index| {
            (1..len + 1)
                .map(|item_index| item_index * row_index)
                .collect()
        })
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn basic() {
        assert_eq!(
            multiplication_table_impl(3),
            [[1, 2, 3], [2, 4, 6], [3, 6, 9]]
        );
    }
}
