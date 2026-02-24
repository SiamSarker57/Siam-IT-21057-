vertical(seg(point(X, _), point(X, _))).

horizontal(seg(point(_, Y), point(_, Y))).

oblique(seg(point(X1, Y1), point(X2, Y2))) :-
    X1 \= X2,
    Y1 \= Y2.

:- initialization((
    vertical(seg(point(5, 10), point(5, 20))) -> write('L1 is Vertical'); write('L1 is not Vertical'), nl,
    horizontal(seg(point(10, 5), point(20, 5))) -> write('L2 is Horizontal'); write('L2 is not Horizontal'), nl,
    oblique(seg(point(10, 10), point(20, 20))) -> write('L3 is Oblique'); write('L3 is not Oblique'), nl
)).