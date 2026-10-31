fn main() {
    {                      // s is not valid here, it’s not yet declared
        let s = "hello";   // s is valid from this point forward

        // do stuff with s
    }                      // this scope is now over, and s is no longer valid

    let mut s = String::from("hello");

    s.push_str(", world!");
    println!("{}", s);

    {
        let s = String::from("hello"); // s is valid from this point forward

        // do stuff with s
    }                                  // this scope is now over, and s is no
                                       // longer valid
    let s1 = String::from("hello");
    let s2 = s1; // s1 no longer valid
    let s3 = s2.clone();
    
    let s1 = String::from("hello");
    let len = calculate_length(&s1);

    change(&mut s1);

    let s = String::from("hello world");

    let hello = &s[..5];
    let world = &s[6..];

    let a = [1, 2, 3, 4, 5];

    let slice  = &a[1..3]

    assert_eq!(slice, &[2, 3])
}

fn calculate_length(s: &String) -> usize {
    s.len()
}

fn change(some_strings: &mut String) {
    some_strings.push_str(", world");
}