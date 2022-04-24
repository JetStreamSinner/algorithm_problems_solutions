enum DigitType {
    Unit,
    Ten,
    Hundred,
    Thousand,
}

impl DigitType {
    fn from_index(index: usize) -> DigitType {
        match index {
            0 => DigitType::Unit,
            1 => DigitType::Ten,
            2 => DigitType::Hundred,
            _ => DigitType::Thousand,
        }
    }
}

fn character_mapper(source: char, digit_type: DigitType) -> String {
    match digit_type {
        DigitType::Unit => unit_mapper(source),
        DigitType::Ten => ten_mapper(source),
        DigitType::Hundred => hundred_mapper(source),
        DigitType::Thousand => thousand_mapper(source),
    }
}

fn unit_mapper(source: char) -> String {
    String::from(match source {
        '1' => "I",
        '2' => "II",
        '3' => "III",
        '4' => "IV",
        '5' => "V",
        '6' => "VI",
        '7' => "VII",
        '8' => "VIII",
        '9' => "IX",
        '0' => "",
        _ => panic!("Wrong character"),
    })
}

fn ten_mapper(source: char) -> String {
    String::from(match source {
        '1' => "X",
        '2' => "XX",
        '3' => "XXX",
        '4' => "XL",
        '5' => "L",
        '6' => "LX",
        '7' => "LXX",
        '8' => "LXXX",
        '9' => "XC",
        '0' => "",
        _ => panic!("Wrong character"),
    })
}

fn hundred_mapper(source: char) -> String {
    String::from(match source {
        '1' => "C",
        '2' => "CC",
        '3' => "CCC",
        '4' => "CD",
        '5' => "D",
        '6' => "DC",
        '7' => "DCC",
        '8' => "DCCC",
        '9' => "CM",
        '0' => "",
        _ => panic!("Wrong character"),
    })
}

fn thousand_mapper(source: char) -> String {
    String::from(match source {
        '1' => "M",
        '2' => "MM",
        '3' => "MMM",
        '4' => "MMMM",
        '5' => "MMMMM",
        '6' => "MMMMMM",
        '7' => "MMMMMMM",
        '8' => "MMMMMMMM",
        '9' => "MMMMMMMMM",
        '0' => "",
        _ => panic!("Wrong character"),
    })
}

pub fn num_as_roman_impl(num: i32) -> String {
    let mut result: String = String::new();
    let num = num.to_string();
    let num_length = num.len();

    for (char_index, char) in num.chars().enumerate() {
        result.push_str(
            character_mapper(char, DigitType::from_index(num_length - char_index - 1)).as_str(),
        );
    }
    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn num_as_roman_test() {
        assert_eq!(num_as_roman_impl(182), "CLXXXII");
        assert_eq!(num_as_roman_impl(1990), "MCMXC");
        assert_eq!(num_as_roman_impl(1875), "MDCCCLXXV");
    }
}
