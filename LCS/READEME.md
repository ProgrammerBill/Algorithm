The Longest Common Subsequence
最长公共子序列

最优子结构:
设X=<x1,x2,...xm>和Y=<y1,y2,...yn>为两个序列,并设Z=<z1,z2..
zk>为X和Y的任意一个LCS

1)如果xm = yn,那么zk = xm = yn 而且Zk-1是Xm-1和Yn-1的一个LCS
2)如果xm != yn,那么zk != xm 蕴含Z是Xm-1和Y的一个LCS
3)如果xm != yn,那么zk !=  蕴含Z是X和Yn-1的一个LCS
