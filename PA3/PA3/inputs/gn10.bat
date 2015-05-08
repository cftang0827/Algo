read_graph inputs/gn10.dot 
//dot -Tpng inputs/gn10.dot -o outputs/gn10.png
//display outputs/gn10.png
write_tree_dfs -s v0 -o outputs/gn10_dfs.dot
//dot -Tpng outputs/gn10_dfs.dot -o outputs/gn10_dfs.png
//display outputs/gn10_dfs.png
write_tree_bfs -s v0 -o outputs/gn10_bfs.dot
color_graph -m greedy -o outputs/gn10_color.dot


exit

