series(R1, R2, Re) :- Re is R1 + R2.
parallel(R1, R2, Re) :- Re is ((R1 * R2) / (R1 + R2)).

calculate_circuit(TotalR) :-
    parallel(10, 40, R_parallel_1),
    series(R_parallel_1, 12, R_middle_branch),
    parallel(R_middle_branch, 30, TotalR).

:- initialization((calculate_circuit(R), format('The equivalent resistance of the circuit is: ~2f Ohm~n', [R]))).