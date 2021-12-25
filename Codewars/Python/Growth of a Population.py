'''
Source : Codewars

In a small town the population is p0 = 1000 at the beginning of a year. 
The population regularly increases by 2 percent per year and moreover 
50 new inhabitants per year come to live in the town. How many years 
does the town need to see its population greater or equal to p = 1200 
inhabitants?
'''

# ngecek berapa tahun dibutuhkan hingga penduduk awal (p0) > penduduk akhir (p)
def nb_year(p0, percent, aug, p):
    year = 0
    # ngeiterasi p0 pake input yang dikasih dan ngeincrement tahun
    while(p0 < p):
        # rumus pertumbuhan penduduk yang dikasih
        p0 = int(p0 * (1+(percent*0.01)) + aug)
        year += 1
    return year

# tes fungsi
result = nb_year(1000, 2, 50, 1200)
print(result)