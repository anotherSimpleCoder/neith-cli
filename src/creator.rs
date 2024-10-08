use crate::utils;
use std::fmt::Write;

pub fn create_service(service_name: &str) {
    let mut code = String::new();
    writeln!(&mut code, "'@service'").unwrap();
    writeln!(&mut code, "class  {} Service {{ }}", utils::to_title_case(service_name)).unwrap();

    utils::write_file(format!("{}.service.ts", service_name).as_str(), code.as_str())
}

pub fn create_component(component_name: &str) {
    utils::write_file(format!("{}.neith", component_name).as_str(), format!("<p>{} works!</p>", component_name).as_str())
}