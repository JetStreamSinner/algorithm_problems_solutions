mod implementations;

pub mod solutions {
    #[allow(dead_code)]
    pub fn rot13(message: &str) -> String {
        super::implementations::rot13_impl(message)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn rot13_test() {
        assert_eq!(solutions::rot13("z"), "m");
        assert_eq!(solutions::rot13("test"), "grfg");
        assert_eq!(solutions::rot13("Test"), "Grfg");
    }
}

