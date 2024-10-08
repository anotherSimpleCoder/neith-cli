mod banner;

use std::fs::File;
use std::io::Write;
use subprocess::Exec;

pub fn title_card() {
    let byte_data = Vec::from(banner::BANNER);
    let title = String::from_utf8(byte_data)
        .expect("FatalError: Invalid banner data!");

    println!("{}", title);
}

pub fn run(command: &str, args: &[&str]) {
    Exec::shell(command)
        .args(args)
        .join()
        .expect("FatalError: Failed to run command!");
}

pub fn write_file(filename: &str, content: &str) {
    let mut file = File::create(filename)
        .expect(format!("FileError: Could not create file {}!", file!()).as_str());

    file.write_all(content.as_bytes())
        .expect("FileError: Could not write content into file!");
}

pub fn to_title_case(str: &str) -> String {
     let string = str.chars().into_iter()
        .next()
        .expect("CharError: Empty string entered!")
        .to_uppercase()
        .collect::<String>();

    string
}