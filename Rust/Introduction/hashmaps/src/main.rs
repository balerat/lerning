use std::collections::HashMap;

let mut scores = HahsMap::new();

scores.insert(String::from("Blue"), 10)
scores.insert(String::from("Yellow"), 50);

let team_name = String::from("Blue");
let score = score.get(&team_name).copied().unwrap_or(0);

for (key, value) in &scores {
    println!("{key}: {value}");
}

use std::collections::HashMap;

let field_name = String::from("Favorite color");
let field_value = String::from("Blue");

let mut map = HashMap::new();
map.insert(field_name, field_value);
// field_name and field_value are invalid at this point, try using them and
// see what compiler error you get!

// Overwriting value

let mut scores = HashMap::new();

scores.insert(String::from("Blue"), 10);
scores.insert(String::from("Blue"), 25);

println!("{:?}", scores);

//Adding a key and value only if a key isn't present

let mut scores = HashMap::new();
scores.insert(String::from("Blue"), 10);

scores.entry(String::from("Yellow")).or_insert(50);
scores.entry(String::from("Blue")).or_insert(50);

println!("{:?}", scores);

// Updating a Value Based on the Old Value

let text = "hello world wonderful world";
let mut map = HahsMap::new();

for world in text.split_whitespace() {
    let count = map.entry(world).or_insert(0);
    *count += 1;
}

