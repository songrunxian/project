#### i want to use this file to practice markdown grammar
#### Markdown 段落的换行是使用两个以上空格加上回车
#### `这是添加底纹`
#### *这是斜体*
# Install:
First, make you have the following installed:
* [Git]
* [Virtual box]
* [Vagrant]
```
git clone https://github.com/mnori/rnasstut.git
cd rnasstut
vagrant up
```
This is an method about finding various RNA structure prediction methods
# Tutorial:
Now ,we need to know what is biopython:  
Biopython是一个用于生物信息学的Python库，提供了许多用于处理生物序列、结构和数据的工具和函数.  
And ,this method use two ways to find RNA structure ------ "RNAstructure", this package is not a package in Biopython.
"RNAstructure"是一个独立的软件包，用于预测和分析RNA的二级结构。它是由University of Rochester Medical Center的David H. Mathews实验室开发的，可以用于预测RNA分子的结构、热力学参数和相互作用能。
```
https://rna.urmc.rochester.edu/RNAstructure.html
``` 
This medthod use two ways to find RNA structture ----- ViennaRNA (this is an python packages)
```
https://pypi.org/project/ViennaRNA/
```
This is an another example about biopython, maybe it can use to predict RNA structure:
```
#Use Biopython
pip install biopython
#This is an example to use biopython:
from Bio import SeqIO
from Bio.SeqUtils import GC
from Bio.SeqUtils.RNA import fold

# Read RNA sequence from a file in FASTA format
record = SeqIO.read("rna_sequence.fasta", "fasta")
rna_sequence = str(record.seq)

# Calculate GC content
gc_content = GC(rna_sequence)
print("GC content:", gc_content)

# Predict secondary structure using RNAfold
structure, mfe = fold(rna_sequence)
print("Secondary structure:", structure)
print("Minimum free energy (MFE):", mfe)
```
## `RNAstructure`: prediction from nucleotide sequence alone
We will first try to predict the secondary structure of an *A. thaliana* 18S rRNA fragment from its sequence alone, using the `RNAstructure` `Fold` method.
### Running `RNAstructure Fold` from the command line
可使用命令行或线上工具  
`线上工具`:*http://rna.urmc.rochester.edu/RNAstructureWeb/Servers/Predict1/Predict1.html* 
在运行“Fold”之前，我们必须设置一个环境变量，它指向一个包含折叠热力学参数的文件夹。 这些是 RNAstructure 包的一部分:
```
export DATAPATH=~/RNAstructure/data_tables
``` 
We can now run `Fold` to predict the RNA structure:
```
~/RNAstructure/exe/Fold ~/data/18s.fasta ~/18s_rnastructure_pred.txt
```
`~/data/18S_rRNA.fasta` is the input sequence (18S rRNA in fasta format).
`~/18s_rnastructure_pred.txt` is the output file.
