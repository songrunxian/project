Fold 18s.fasta 18s_rnastructure_pred_constrained.txt -dms 18s_constraints_rnastructure.txt
ct2dot 18s_rnastructure_pred_constrained.txt 1 18s_rnastructure_pred_constrained.dot.txt
sed "1s/.*/\>rnastructure_strict/" 18s_rnastructure_pred_constrained.dot.txt > 18s_rnastructure_pred_constrained.dot
RNAplot -o svg < 18s_rnastructure_pred_constrained.dot
