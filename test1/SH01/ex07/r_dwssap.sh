cat /etc/passwd | grep '^[^#]'| awk " NR%2==0 {print}" | cut -f 1 -d : | rev |sort -r | awk -v a=$FT_LINE1 -v b=$FT_LINE2 'BEGIN{ORS=", "} NR==a,NR==b {print}' | sed  's/, $/./' | tr -d '\n'
