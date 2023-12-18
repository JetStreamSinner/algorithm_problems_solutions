mod roman_decoder;
mod unique_in_order;

mod codewars {
    use super::roman_decoder;
    use super::unique_in_order;
    use super::unique_in_order::unique_in_order_impl;

    pub fn roman_as_num(roman: &str) -> u64 {
        roman_decoder::decode(roman)
    }

    pub fn unique_in_order<T>(sequence: T) -> Vec<T::Item>
    where
        T: std::iter::IntoIterator,
        T::Item: std::cmp::PartialEq + std::fmt::Debug + Copy,
    {
        unique_in_order_impl(sequence)
    }
}
