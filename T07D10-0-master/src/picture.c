#include <stdio.h>
#define N 15
#define M 13

void transform(int buf[][M], int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void output_picture(int **picture, int n, int m);

int main(void)
{
   int picture_data[N][M];
   int *picture[N];
   transform(picture_data, picture, N, M);

   make_picture(picture, N, M);
   output_picture(picture, N, M);
   return 0;
}

void make_picture(int **picture, int n, int m)
{
   int frame_w[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
   int frame_h[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
   int tree_trunk[] = { 7, 7, 7, 7 };
   int tree_foliage[] = { 3, 3, 3, 3 };
   int sun_data[6][5] = { { 0, 6, 6, 6, 6 }, 
                          { 0, 0, 6, 6, 6 }, 
                          { 0, 0, 6, 6, 6 },
                          { 0, 6, 0, 0, 6 },
                          { 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0 } };

   reset_picture(picture, n, m);

   int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
   int height_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);
   
   for (int i = 0; i < length_frame_w; i++) {
      picture[0][i] = frame_w[i];
      picture[n-1][i] = frame_w[i];
      picture[(n-1)/2][i] = frame_w[i];
   }
   for (int i = 0; i < height_frame_h; i++) {
      picture[i][0] = frame_h[i];
      picture[i][m-1] = frame_h[i];
      picture[i][(m-1)/2] = frame_h[i];
   }
   for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 5; j++) {
         picture[i + 1][j + 7] = sun_data[i][j];
      }
   }
   for (int i = 0; i < 1; i++) {
      for (int j = 0; j < 4; j++) {
         picture[i + 10][j + 2] = tree_trunk[j];
         picture[i + 3][j + 2] = tree_foliage[j];
         picture[i + 4][j + 2] = tree_foliage[j];
         if (j < 2) {
            picture[i + 5][j + 3] = tree_foliage[j];
            picture[i + 2][j + 3] = tree_foliage[j];
            picture[i + 9][j + 3] = tree_trunk[j];
            picture[i + 8][j + 3] = tree_trunk[j];
            picture[i + 6][j + 3] = tree_trunk[j];
         }

      }
   }
      
      
}

void reset_picture(int **picture, int n, int m)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         picture[i][j] = 0;
      }  
   }
}

void transform(int buf[][M], int **matr, int n, int m) {  
   for(int i = 0; i < n; i++) {
      matr[i] = (int *)buf + i * m;
   }
}

void output_picture(int **picture, int n, int m) {
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         printf("%d ", picture[i][j]);
      }
      printf("\n");
   }
}
