

ok so think about it, we are gonna use this weird ass ECS system

Since this focuses sooo much on cellular automata we will focus the design on two main ideas:
1. cell
   1. cells need to contain physics information
   2. cells need to contain further components for other interactions (rendering, specialized interactions, game mechanics)
2. entity (can be composed of cells and what not)
   1. rendering components (think if this is really nessecary, if everything that is rendered are cells)
   2. mat4 (positional and orientation data)
   3. further game logic components
   4. physics components (maybe rigid bodies / soft bodies with cellular automata)

Here lies the main issue: how do we progress these two interactions
- treat EVERYTHING as automata (movements will occur globally in a frame by frame basis)
- treat SOMETHINGS as automata (other objects will have typical iterative solver)

first method seems way more interesting, so ill try to stick with that instead.

Consider Data Driven Design: focus on the the components and less on the entities. This wont make sense for the cells however, since cell properties will need to be intrinsic and closely tied.
- entities: literally just an id that groups a bunch of properties together


Super interesting behaviour:
- rigid/soft dynamics
- emergent behaviour (floating, interactions, reactions)
- perhaps introduce the notion of vector force fields and eulerian grids (gonna be messed up to implement tho)
- dynamic behaviour of entities (shattering, movement, rotations, deformation, friction, etc)

## Random other stuff
Consider the following: https://www.youtube.com/watch?v=5glH8dGoeCA 

Consider using the following: -fsanitize=address -lasan AddressSanitizer also LeakSanitizer ThreadSanitizer MemorySanitizer

consider offloading computation to fragment shader (use compute shaders), keep vertex shader simple