pub fn list_squared_impl(m: u64, n: u64) -> Vec<(u64, u64)> {
    (m..n + 1)
    .map(|i| (i, sum_squared_divs(i)))
    .filter(|&(_, sq)| is_square(sq))
    .collect()
}

fn is_square(n: u64) -> bool {
    let t = (n as f64).sqrt() as u64;
    t * t == n
}

fn sum_squared_divs(n: u64) -> u64 {
    (1..)
    .take_while(|i| i * i <= n)
    .filter(|i| n % i == 0)
    .fold(0, |acc, i| acc + (if i * i == n { n } else { i * i + (n / i) * (n / i) }))
}

fn testing(m: u64, n: u64, exp: Vec<(u64, u64)>) -> () {
    assert_eq!(list_squared_impl(m, n), exp)
}

#[test]
fn basics_list_squared() {
    testing(1, 250, vec![(1, 1), (42, 2500), (246, 84100)]);
    testing(42, 250, vec![(42, 2500), (246, 84100)]);
    testing(300, 600, vec![]);
}
