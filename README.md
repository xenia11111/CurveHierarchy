A small program in C++ that implements support of 3D curves hierarchy.
1. Supports a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified 
definitions are below). Each curve is able to return a 3D point and a first derivative (3D 
vector) per parameter t along the curve.
2. Populates a container (std::vector) of objects of these types created in random manner with 
random parameters.
3. Prints coordinates of points and derivatives of all curves in the container at t=PI/4.
4. Populates a second container that contains only circles from the first container. Second container shares (i.e. not clones) circles of the first one via std::shared_ptr.
5. Sorts the second container in the ascending order of circles’ radii. That is, the first element has the 
smallest radius, the last - the greatest.
6. Computes the total sum of radii of all curves in the second container in parallel, using Parallel STL.
7. The implementation is split into a library of curves (CurveHierarchy.dll) and executable (Main.exe) which uses API of this 
library.
