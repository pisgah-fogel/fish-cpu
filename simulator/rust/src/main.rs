mod log;
mod traits;

fn main() {
	let mut a : u32 = 10;

	println!("While loop:");
	while a != 0 {
		println!("{}", a);
		a-=1;
	}

	println!("Array:");
	let mut a : [i32; 5] = [10, 20, 30, 40, 50];

	println!("Size: {}", get_size(&a));	
	println!("Let's modify array");
	modify(&mut a);
	println!("iteration through:");
	for b in a.iter() {
		println!("{}", b);
	}

	println!("count");
	for b in (2..10).rev() {
		println!("{}", b);
	}

	println!("String operation");
	let mut s = String::from("Hello");
    println!("\"{}\"", s);
	println!("Append to string");
	add_string(&mut s);
    println!("\"{}\"", s);

	println!("Create a User: Aubin");
	let mut aubin = User {
		email: String::from("test@mail.com"),
		username: String::from(""),
		active: true,
		sign_in_count: 3
	};
	println!("modify user");
	aubin.email = String::from("test@example.com");
	println!("Print user:");
	aubin.print();

	println!("Create a collection");
	let mut list = AveragedCollection::new();
	/*let list2 = AveragedCollection {
		list: vec![1, 2, 3],
		average: 0.0
	};*/
	list.add(1);
	list.add(2);
	list.add(3);
	println!("Average: {}", list.average());
	println!("Create point");
	
	let c = Point { x: 2, y:4.3 };
	c.print();
	println!("Test, x: {}", c.get_x());
	println!("Test, y: {}", c.get_y());

	let c = Point { x: 2.1, y:4.3 };
	println!("{}", c.distance_from_origin());

	log::print();

	traits::test();
}

fn get_size(ptr: &[i32]) -> usize {
	ptr.len()
}

fn modify(ptr: &mut [i32]) {
	ptr[0] = 0;
}

fn add_string(ptr: &mut String) {
	ptr.push_str(", world!");
}

#[derive(Debug)]
struct User {
	username: String,
	email: String,
	sign_in_count: u64,
	active: bool
}

impl User {
	fn print(&self) {
		println!("{} {} {} {}", self.username, self.email, self.sign_in_count, self.active);
	}
}

pub struct AveragedCollection {
	list: Vec<i32>,
	average: f64
}

impl AveragedCollection {
	pub fn new() -> AveragedCollection {
		let list = Vec::new();
		let average = 0.0;
		AveragedCollection {
			list: list,
			average: average
		}
	}

	pub fn add(&mut self, value: i32) {
		self.list.push(value);
		self.update_average();
	}
	
	pub fn remove(&mut self) -> Option<i32> {
		let result = self.list.pop();
		match result {
			Some(value) => {
				self.update_average();
				Some(value)
			},
			None => None
		}
	}
	
	pub fn average(&self) -> f64 {
		self.average
	}
	
	// private
	fn update_average(&mut self) {
		let total: i32 = self.list.iter().sum();
		self.average = total as f64 / self.list.len() as f64;
	}
}

struct Point<T, V> {
    x: T,
    y: V,
}

impl<T, V> Point<T, V> {
    pub fn get_x(&self) -> &T {
        &self.x
    }
    pub fn get_y(&self) -> &V {
        &self.y
    }
}

// std::fmt::Display
// implement method on a generic type depending on trait bound
// https://doc.rust-lang.org/book/ch10-02-traits.html
impl<T: std::fmt::Display, V: std::fmt::Display> Point<T, V> {
	pub fn print(&self) {
		println!("Point x:{} y:{}", self.x, self.y);
	}
}

impl Point<f32, f32> {
    fn distance_from_origin(&self) -> f32 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

//fn longest_with_an_announcement<'a, T>(x: &'a str, y: &'a str, ann: T) -> &'a str
//    where T: std::fmt::Display
//{
//    println!("Announcement! {}", ann);
//    if x.len() > y.len() {
//        x
//    } else {
//        y
//    }
//}
