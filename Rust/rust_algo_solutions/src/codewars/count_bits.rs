pub fn count_bits_impl(mut n: i64) -> u32 {
    let mut bits_counter = 0;
    const BIT_MASK: i64 = 0x1;
    while n != 0 {
        if n & BIT_MASK == 1 {
            bits_counter += 1;
        }
        n >>= 1;
    }
    bits_counter
}

#[test]
fn returns_expected() {
    assert_eq!(count_bits_impl(0), 0);
    assert_eq!(count_bits_impl(4), 1);
    assert_eq!(count_bits_impl(7), 3);
    assert_eq!(count_bits_impl(9), 2);
    assert_eq!(count_bits_impl(10), 2);
}
