#include "dbh.h"

int avw_read(char* filename,struct dsr *header);
int avw_write(char* filename,struct dsr *header);
void avw_init(struct dsr *header,int x,int y,int z,int v,int t);
void xtrt_filepath(char *in,char *out);
void avw_set_dim(struct dsr *header,int x,int y,int z,int v);
void avw_get_dim(struct dsr *header,int *x,int *y,int *z,int *v);
void avw_set_dt(struct dsr *header,int dt);
void avw_get_dt(struct dsr *header,int *dt);
void avw_set_maxmin(struct dsr *header,int max,int min);
void avw_get_maxmin(struct dsr *header,int *max,int *min);
void avw_set_vox(struct dsr *header,float vx,float vy,float vz);
void avw_get_vox(struct dsr *header,float *vx,float *vy,float *vz);
void avw_set_orient(struct dsr *header,char orient);
void avw_get_orient(struct dsr *header,char *orient);
void avw_set_tr(struct dsr *header,float tr);
void avw_get_tr(struct dsr *header,float *tr);
void avw_set_study(struct dsr *header,char *study);
void avw_get_study(struct dsr *header,char *study);
void avw_set_scannum(struct dsr *header,char *scannum);
void avw_get_scannum(struct dsr *header,char *scannum);
void avw_set_date(struct dsr *header,char *date);
void avw_get_date(struct dsr *header,char *date);
void avw_get_descrip(struct dsr *header,char *string);
void avw_set_descrip(struct dsr *header,char *string);
void avw_set_patient(struct dsr *header,char *string);
void avw_get_patient(struct dsr *header,char *string);
void avw_swap_xy(struct dsr *header);
int avw_xdim(struct dsr *header);
int avw_ydim(struct dsr *header);
int avw_zdim(struct dsr *header);
int avw_vdim(struct dsr *header);
int avw_dt(struct dsr *header);
float avw_xvox(struct dsr *header);
float avw_yvox(struct dsr *header);
float avw_zvox(struct dsr *header);
float avw_tr(struct dsr *header);
char avw_orient(struct dsr *header);
int avw_compare_dim(struct dsr *header1,struct dsr *header2);