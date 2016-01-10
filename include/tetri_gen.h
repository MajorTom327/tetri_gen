#ifndef TETRI_GEN_H
# define TETRI_GEN_H
# define BUF_SIZE 21

unsigned short	*tetri_read(char *path);
void			tetri_validate(unsigned short tetri);
int				tetri_generate(int nb);
#endif /* TETRI_GEN_H */
