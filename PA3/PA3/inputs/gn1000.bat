read_graph inputs/gn1000.dot 
//dot -Tpng inputs/gn1000.dot -o outputs/gn1000.png
//display outputs/gn1000.png
write_tree_dfs -s v0 -o outputs/gn1000_dfs.dot
//dot -Tpng outputs/gn1000_dfs.dot -o outputs/gn1000_dfs.png
//display outputs/gn1000_dfs.png
write_tree_bfs -s v0 -o outputs/gn1000_bfs.dot
color_graph -m greedy -o outputs/gn1000_color.dot


exit

