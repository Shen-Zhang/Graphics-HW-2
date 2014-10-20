Graphics-HW-2
=============

A basic curve editor which supports the following:
The user can create objects by pressing down the 'P', 'L', or 'B' key --- Polyline, Lagrange, or Bezier, respectively. Control points can be added by mouse clicks as long as the key is held down. Releasing the key deletes the selected object if it has less then two control points. The object being created is always the selected one, and is drawn as such. The control points of the selected curve are also drawn.

- Pressing SPACE makes the next object selected instead of the current one, repeatedly pressing SPACE cycles over all curves. 
- As long as the mouse button remains pressed, mouse movements drag the selected object. When the button is released, the object remains selected.
- When an object is selected, the user may hold down 'A' to add control points to the selected object by clicking. 
- Support removing control points of the selected curve, by holding 'D' and clicking them.
- Support Catmull-Clark subdivision curves, created by clicking control points while holding key 'C'. 
- Support Catmull-Rom splines, created by clicking control points while holding key 'R'. 
- Support dragging control points of the selected curve. 
- Display the current number of curves in the corner using Bezier curves to form the numbers (steal control points from http://jackf.net/bezier-clock/)



Citation:
http://14fall.ait-budapest.com/mod/assign/view.php?id=158&action=editsubmission
http://jackf.net/bezier-clock/
Catmull-Rom Splines: http://www.mvps.org/directx/articles/catmull/#demo 
Object dragging: http://www.sm.luth.se/csee/courses/smd/171/L2.java
Curves knowledge: https://www.cs.utexas.edu/~fussell/courses/cs384g/lectures/lecture16-Interpolating_curves.pdf