mod help;
mod utils;
mod project_gen;
mod creator;

use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        utils::title_card();
        help::help();
        return;
    }

    route(&args[1..args.len()]);
    return;
}

fn route(args: &[String]) {
    if args[0] == "new" {
        project_gen::generate(args[1].as_str());
    }

    if args[0] == "serve" {
        utils::run("cmd /c deno task dev");
    }

    if args[0] == "service" {
        creator::create_service(args[1].as_str());
    }

    if args[0] == "component" {
        creator::create_component(args[1].as_str());
    }
}
