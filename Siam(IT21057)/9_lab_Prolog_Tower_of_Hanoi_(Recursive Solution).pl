% Towers of Hanoi recursive solution

move(1, Source, Target, _) :-
    write('Move disk from '), write(Source), write(' to '), write(Target), nl.

move(N, Source, Target, Aux) :-
    N > 1,
    M is N - 1,
    move(M, Source, Aux, Target),
    move(1, Source, Target, _),
    move(M, Aux, Target, Source).

hanoi(N) :-
    move(N, 'Left Tower', 'Right Tower', 'Center Tower').

:- initialization(hanoi(3)).