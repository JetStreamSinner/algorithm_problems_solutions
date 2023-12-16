mod roman_decoder;

mod codewars {
    use super::roman_decoder;

    fn roman_as_num(roman: &str) -> u64 {
        roman_decoder::decode(roman)
    }
}
