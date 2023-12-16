pub fn decode(roman: &str) -> u64 {
    0
}

#[cfg(test)]
mod roman_decoder_test {
    use super::decode;

    fn test_equal(input: &str, actual: u64, expected: u64) {
        assert_eq!(actual, expected, "\nYour result (left) did not match the expected output (right) for the input \"{}\"", input);
    }
    
    #[test]
    fn basic() {
        test_equal("", decode(""), 0);
        test_equal("I", decode("I"), 1);
        test_equal("XXI", decode("XXI"), 21);
        test_equal("MMVIII", decode("MMVIII"), 2008);
        test_equal("MDCLXVI", decode("MDCLXVI"), 1666);
    }
    
    #[test]
    fn one_through_ten() {
        test_equal("I", decode("I"), 1);
        test_equal("II", decode("II"), 2);
        test_equal("III", decode("III"), 3);
        test_equal("IV", decode("IV"), 4);
        test_equal("V", decode("V"), 5);
        test_equal("VI", decode("VI"), 6);
        test_equal("VII", decode("VII"), 7);
        test_equal("VIII", decode("VIII"), 8);
        test_equal("IX", decode("IX"), 9);
        test_equal("X", decode("X"), 10);
    }
    
    #[test]
    fn big_numbers() {
        test_equal("C", decode("C"), 100);
        test_equal("CDXLIV", decode("CDXLIV"), 444);
        test_equal("M", decode("M"), 1000);
        test_equal("MCMLIV", decode("MCMLIV"), 1954);
        test_equal("MCMXC", decode("MCMXC"), 1990);
        test_equal("MM", decode("MM"), 2000);
        test_equal("MMVIII", decode("MMVIII"), 2008);
        test_equal("MMM", decode("MMM"), 3000);
        test_equal("MMMCM", decode("MMMCM"), 3900);
        test_equal("MMMCMXIV", decode("MMMCMXIV"), 3914);
    }    
}