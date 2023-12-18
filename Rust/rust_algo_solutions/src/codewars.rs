mod list_squared;
mod multiplication_table;
mod roman_decoder;
mod unique_in_order;

mod codewars {
    use super::list_squared;
    use super::multiplication_table;
    use super::roman_decoder;
    use super::unique_in_order;

    pub fn roman_as_num(roman: &str) -> u64 {
        roman_decoder::decode(roman)
    }

    pub fn unique_in_order<T>(sequence: T) -> Vec<T::Item>
    where
        T: std::iter::IntoIterator,
        T::Item: std::cmp::PartialEq + std::fmt::Debug + Copy,
    {
        unique_in_order::unique_in_order_impl(sequence)
    }

    pub fn list_squared(m: u64, n: u64) -> Vec<(u64, u64)> {
        list_squared::list_squared_impl(m, n)
    }

    pub fn multiplication_table(len: usize) -> Vec<Vec<usize>> {
        multiplication_table::multiplication_table_impl(len)
    }
}
