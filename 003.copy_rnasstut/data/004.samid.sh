#我们的目标是修改每个序列的id
sed "1s/.*/\>rnastructure/" 18s_rnastructure_pred.dot.txt > rnastructure.dot
sed "1s/.*/\>vienna/" 18s_vienna_pred.txt > vienna.dot
