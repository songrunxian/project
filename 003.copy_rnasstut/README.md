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
`线上工具`:*http://rna.urmc.rochester.edu/RNAstructureWeb/Servers/Predict1/Predict1.html* but this website maybe wrong 
在运行“Fold”之前，我们必须设置一个环境变量，它指向一个包含折叠热力学参数的文件夹。 这些是 RNAstructure 包的一部分:  
We need to download tools, and RNAstructure `*Registration Form*` just like this :
```
Name: 宋润先
Institution: 东北师范大学
Department: 遗传学院
E-mail address: 13359850710@163.com
``` 
```
export DATAPATH=~/RNAstructure/data_tables
``` 
We can now run `Fold` to predict the RNA structure:
```
~/RNAstructure/exe/Fold ~/data/18s.fasta ~/18s_rnastructure_pred.txt
or please read 001.Fold.sh
```
`~/data/18S_rRNA.fasta` is the input sequence (18S rRNA in fasta format).
`~/18s_rnastructure_pred.txt` is the output file.
### The output
Open `~/18s_rnastructure_pred.txt`,  
This is a `*Connectivity Table (CT) file*`, described in detail.
```
CT文件包含序列的二级结构信息,Its format just like this: 
Start of first line: number of bases in the sequence
End of first line: title of the structure  
Each of the following lines provides information about a given base in the sequence. Each base has its own line, with these elements in order:  
* Base number: index n  
* Base (A, C, G, T, U, X)  
* Index n-1  
* Index n+1  
* Number of the base to which n is paired. No pairing is indicated by 0 (zero).  
* Natural numbering. RNAstructure ignores the actual value given in natural numbering, so it is easiest to repeat n here.  本案例中有3个结果表示，rnastructure，预测的3个结构, 中间的energy表示自由能，我理解为预测分数，分数越低可能性越大 
```
## `ViennaFold`: prediction from nucleotide sequence alone  
`ViennaFold` 是一种替代的基于热力学的 RNA 结构预测方法.  
### Running `Vienna RNAfold` from the command line  
First we need to download tools:  
sudo apt install vienna-rna  
conda install -c bioconda viennarna  
pip install ViennaRNA [https://pypi.org/project/ViennaRNA/]
```
RNAfold < ~/data/18s.fasta > ~/18s_vienna_pred.txt
or Please read 002.RNAfold.sh
In this example 配对的碱基用圆括号表示，而不配对的碱基用点表示
In this example, only the MFE structure is listed. The free energy estimate is provided at the end of the file.
```
## Viewing predicted structures
We're going to compare `RNAstructure` and `Vienna` predictions, but first we need to make sure both structure files are in the same format. To convert RNAstructure's CT file into dot bracket notation, use:  
```
~/RNAstructure/exe/ct2dot ~/18s_rnastructure_pred.txt 1 ~/18s_rnastructure_pred.dot.txt 
or Please read 003.ct2dot.sh
```
Before we plot the structures, we should add a better label  to the beginning of each file. 
```
sed "1s/.*/\>rnastructure/" ~/18s_rnastructure_pred.dot.txt > rnastructure.dot
sed "1s/.*/\>vienna/" ~/18s_vienna_pred.txt > vienna.dot
or Please read 004.sameid.sh
```
We can now generate structure diagrams for both predictions using `Vienna`'s `RNAplot`:

```
RNAplot -o svg < ~/rnastructure.dot
RNAplot -o svg < ~/vienna.dot
or Please read 005.picture.sh
```
## `RNAstructure`: prediction using sequence and constraints
So far, we've predicted RNA structures using sequence alone. This is not particularly accurate. We can try to improve the prediction by including extra information from a chemical probing experiment. These extra data are called constraints, and *RNAstructure* uses these in the thermodynamics calculations as pseudo free energy terms.  
到目前为止，我们已经仅使用序列预测了 RNA 结构。 这不是特别准确。 我们可以尝试通过包含来自化学探测实验的额外信息来改进预测。 这些额外的数据称为约束，*RNAstructure* 在热力学计算中将这些数据用作伪自由能项。  
We'll be using constraints generated from a dimethyl sulfate (DMS) probing experiment of the 18S rRNA. DMS reacts with C and A nucleotides that are not involved in base pairing. The experiment produces normalised reactivity values. Values approaching 1 or above indicate a strong reactivity and thus a high probability that the corresponding base is unpaired.  
我们将使用从 18S rRNA 的硫酸二甲酯 (DMS) 探测实验生成的约束。 DMS 与不参与碱基配对的 C 和 A 核苷酸发生反应。 实验产生归一化的反应性值。 接近 1 或以上的值表示强烈的反应性，因此相应碱基未配对的可能性很高。  
### The constraints file
The file `~/data/18s_constraints_rnastructure.txt` contains normalised DMS reactivities in a format that `RNAstructure` understands.  
This file just like this:  
```
2	0.012685795205
3	0.0
4	0.0
11	0.369865767367
13	0.0
14	0.0
17	0.0
18	0.0
19	0.0
22	0.291074839291
...
```
第一列是序列位置，第二列是标准化的 DMS 反应性。 缺失的位置是 G 或 U 核苷酸，其中 DMS 反应性不适用。  
We'll now run a prediction using these constraints:
```
Fold 18s.fasta 18s_rnastructure_pred_constrained.txt -dms 18s_constraints_rnastructure.txt
```
You can check out the output by drawing a structure plot as described earlier.
or Please see 006.strictFold.sh
## `ViennaFold`: prediction from sequence and constraints
The file `18s_constraints_vienna.txt` contains some constraints in `ViennaRNA`'s format:  
```
>Ath_18S
TACCTGGTTGATCCTGCCAGTAGTCATATGCTTGTCTCAAAGATTAAG ...
.|||........||..|||..|..||.|..|....|...x..x..... ...
```
`.` 表示没有约束，`|` 表示碱基必须配对，`x` 表示碱基必须不配对  
A detailed description of the format can be found [here](http://www.tbi.univie.ac.at/RNA/RNAfold.html).
这些 Vienna 约束是通过将反应性值低于 0.3 的任何碱基视为配对的，将高于 0.7 的任何值视为未配对的碱基而产生的。 反应性介于 0.3 和 0.7 之间的碱基被认为是不明确的，不受约束。 这是处理数据的一种非常粗略的方式； 在实践中，人们可能想尝试不同的分类阈值。
```
RNAfold < ~/data/18s_constraints_vienna.txt > ~/18s_vienna_pred_constrained.txt -C
```
额外的“-C”选项表示我们正在约束模式下运行。
## Determining structure prediction accuracy[确定结构预测精度]
We can assess the performance of each prediction by comparing against a high-confidence reference stucture. The best structure available for the 18S rRNA comes from phylogenetic comparisons. The file `18s_phylogenetic.txt` contains a summary of this structure:
我们可以通过与高置信度参考结构进行比较来评估每个预测的性能。18S rRNA的最佳结构来自系统发育比较。文件“18s_systematicy.txt”包含此结构的摘要：
```
1	T	s
2	A	s
3	C	s
4	C	d
5	T	d
6	G	d
7	G	d
8	T	s
9	T	s
10	G	s
...
```
Column 1 is the position, column 2 the base, 在第3列中，“s”表示碱基是单链的，而“d”表示碱基成对（即双链）.
为了评估准确性，我们将每个预测与参考进行比较，并计算每个位置的真阳性（TP）、真阴性（TN）、假阳性（FN）和假阴性（FN）。我们将使用python脚本来完成此操作。为了将RNA结构*在计算机上*和*在体内*的预测与系统发育结构进行比较：
`python3 ~/utils/compare_structures.py -r=~/18s_rnastructure_pred.txt ~/data/18s_phylogenetic.txt`

`python3 ~/utils/compare_structures.py -r=~/18s_rnastructure_pred_constrained.txt ~/data/18s_phylogenetic.txt`

Likewise the `ViennaFold` predictions can be compared against the phylogenetic structure:

`python3 ~/utils/compare_structures.py -v=~/18s_vienna_pred.txt ~/data/18s_phylogenetic.txt`

`python3 ~/utils/compare_structures.py -v=~/18s_vienna_pred_constrained.txt ~/data/18s_phylogenetic.txt`

You should see a slight improvement in predictive performance when secondary structure constraints are used.

我们需要使用片段，因为18S rRNA的几个区域被蛋白质覆盖，这会干扰结构预测。位置1345和1435之间的片段给出了不错的结果，因为它只包含片段内的相互作用的蛋白。
如果您想尝试不同的片段，脚本utils/make_fragment.py会将开始和停止位置作为参数，并生成前缀为“18s_”的文件，这些文件可以用作预测的输入，如前所述。  
```
python3 make_fragment.py 100 200
```
选择要测试的片段时，可以参考18S结构图`~/data/18S_structure_diagram.png`。
