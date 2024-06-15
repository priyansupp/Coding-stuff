Line 1. Oval -> Start
Line 2. Parallelogram -> READ A, B
Line 3. Diamond -> hh1 <- {A-(A%100)}/100
Line 4. Diamond -> mm1 <- A%100
Line 5. Diamond -> hh2 <- {B-(B%100)}/100
Line 6. Diamond -> mm2 <- B%100
Line 7. Rectangle -> C <- (hh1-hh2)*60 + (mm1-mm2)
Line 8. Parallelogram -> print C
Line 9. Oval -> Stop