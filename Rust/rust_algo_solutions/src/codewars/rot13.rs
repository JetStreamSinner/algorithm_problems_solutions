// Rot13

// ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters
// after it in the alphabet. ROT13 is an example of the Caesar cipher.
// Create a function that takes a string and returns the string ciphered with Rot13.
// If there are numbers or special characters included in the string,
// they should be returned as they are. Only letters from the latin/english alphabet
// should be shifted, like in the original Rot13 "implementation".

struct LettersBound {
    lower: u32,
    upper: u32,
}

const UPPER_MIN: u32 = 65;
const UPPER_MAX: u32 = 90;
const UPPER_BOUND: LettersBound = LettersBound {
    lower: UPPER_MIN,
    upper: UPPER_MAX,
};

const LOWER_MIN: u32 = 97;
const LOWER_MAX: u32 = 122;
const LOWER_BOUND: LettersBound = LettersBound {
    lower: LOWER_MIN,
    upper: LOWER_MAX,
};

const OTHER_MIN: u32 = 0;
const OTHER_MAX: u32 = 0;
const OTHER_BOUND: LettersBound = LettersBound {
    lower: OTHER_MIN,
    upper: OTHER_MAX,
};

enum LetterType {
    Upper,
    Lower,
    Other,
}

impl LetterType {
    fn value(&self) -> LettersBound {
        match *self {
            LetterType::Upper => UPPER_BOUND,
            LetterType::Lower => LOWER_BOUND,
            LetterType::Other => OTHER_BOUND,
        }
    }
}

fn shift_char(char_ord: u32, offset: u32, case: LetterType) -> u32 {
    let shifted_ord = char_ord + offset;
    let case_bounds = case.value();

    let overflowed = shifted_ord > case_bounds.upper;

    if overflowed {
        let overflow_tail = offset - (case_bounds.upper - char_ord) - 1;
        let tailed_ord = case_bounds.lower + overflow_tail;
        return tailed_ord;
    }
    shifted_ord
}

pub fn rot13_impl(message: &str) -> String {
    let mut transformed = String::new();

    const SHIFT_OFFSET: u32 = 13;

    for character in message.bytes() {
        let target_case = if character.is_ascii_alphabetic() {
            if character.is_ascii_lowercase() {
                LetterType::Lower
            } else {
                LetterType::Upper
            }
        } else {
            LetterType::Other
        };

        let shifted = match target_case {
            LetterType::Upper | LetterType::Lower => {
                shift_char(character as u32, SHIFT_OFFSET, target_case)
            }
            LetterType::Other => character as u32,
        };
        transformed.push(shifted as u8 as char);
    }
    transformed
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn rot13_test() {
        assert_eq!(rot13_impl("z"), "m");
        assert_eq!(rot13_impl("test"), "grfg");
        assert_eq!(rot13_impl("Test"), "Grfg");
    }
}
