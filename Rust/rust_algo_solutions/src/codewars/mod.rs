mod roman_encoder;
mod rot13;

pub mod solutions {
    #[allow(dead_code)]
    pub fn rot13(message: &str) -> String {
        super::rot13::rot13_impl(message)
    }
    pub fn num_as_roman(num: i32) -> String {
        super::roman_encoder::num_as_roman_impl(num)
    }
}
