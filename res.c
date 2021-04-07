void result()
{
	FILE *f,*fk;
	int i;
	fk = fopen("zapis.txt","r");
    fscanf(fk,"%i",&number_res_file);
  	fclose(fk); 
	printf("\n++++++++++++TABLE Records+++++++++++++\n\n");
	printf("\n        Player    -    Score");
	printf("\n......................................\n");
	res Res=(res)calloc(number_res_file,sizeof(struct Results));
	f = fopen("res.txt","r");
	for(i=0;i<number_res_file;i++){
		fscanf(f,"%s%d",Res[i].player,&Res[i].highscore);
		printf("%i. %12s    -    %12i\n",i+1,Res[i].player,Res[i].highscore);

	}
	fclose(f);
    free(Res);
}
