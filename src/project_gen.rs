use crate::utils;
use std::fmt::Write;
use std::fs::create_dir;

pub fn generate(proj_name: &str) {
    create_dir(proj_name)
        .expect(format!("FileError: Could not create the directory {}", proj_name).as_str());


    utils::run("cd", &[proj_name, "&&", "deno", "init"]);
    write_routes(proj_name);
    write_main_ts(proj_name);
    write_deno_json(proj_name);
    utils::run("cd", &[proj_name, "&&", "deno", "cache", "."]);
}

fn write_routes(proj_name: &str) {
    let mut code = String::new();
    writeln!(&mut code, "import {{ Route }} from 'https://github.com/anotherSimpleCoder/neith/raw/main/mod.ts';").unwrap();
    writeln!(&mut code, "").unwrap();
    writeln!(&mut code, "export const routes: Route[] = [];").unwrap();

    utils::write_file(format!("{}/routes.ts", proj_name).as_str(), code.as_str());
}

fn write_main_ts(proj_name: &str) {
    let mut code = String::new();
    writeln!(&mut code, "import {{ NeithServer }} from 'https://github.com/anotherSimpleCoder/neith/raw/main/mod.ts';").unwrap();
    writeln!(&mut code, "import {{ routes }} from './routes.ts';").unwrap();
    writeln!(&mut code, "").unwrap();
    writeln!(&mut code, "NeithServer").unwrap();
    writeln!(&mut code, "\t.fromRoutes(routes)").unwrap();
    writeln!(&mut code, "\t.serve(3000);").unwrap();

    utils::write_file(format!("{}/main.ts", proj_name).as_str(), code.as_str());
}

fn write_deno_json(proj_name: &str) {
    let mut code = String::new();
    writeln!(&mut code, "{{").unwrap();
    writeln!(&mut code, "\t\"tasks\": {{").unwrap();
    writeln!(&mut code, "\t\t\"dev\": \"deno run --watch main.ts\"").unwrap();
    writeln!(&mut code, "\t}}").unwrap();
    writeln!(&mut code, "}}").unwrap();


    utils::write_file(format!("{}/deno.json", proj_name).as_str(), code.as_str());
}