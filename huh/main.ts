import { NeithServer } from 'https://github.com/anotherSimpleCoder/neith/raw/main/mod.ts';
import { routes } from './routes.ts';

NeithServer
	.fromRoutes(routes)
	.serve(3000);
