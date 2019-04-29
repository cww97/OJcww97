program cx;
var i,n,t,j:longint;
    g:array[0..10,0..10]of longint;
    v:array[0..10]of boolean;

function check():boolean;
var i,j:longint;
begin
  for i:=1 to 9 do
    begin
      fillchar(v,sizeof(v),0);
      for j:=1 to 9 do 
        if v[g[i,j]] then exit(false)
          else v[g[i,j]]:=true;
    end;

  for i:=1 to 9 do
    begin
      fillchar(v,sizeof(v),0);
      for j:=1 to 9 do 
        if v[g[j,i]] then exit(false)
          else v[g[j,i]]:=true;
    end;


  fillchar(v,sizeof(v),0);             //1
  for i:=1 to 3 do
    for j:=1 to 3 do
      if v[g[i,j]] then exit(false)
        else v[g[i,j]]:=true;

  fillchar(v,sizeof(v),0);             //2
  for i:=1 to 3 do
    for j:=4 to 6 do
      if v[g[i,j]] then exit(false)
        else v[g[i,j]]:=true;

  fillchar(v,sizeof(v),0);             //3
  for i:=1 to 3 do
    for j:=7 to 9 do
      if v[g[i,j]] then exit(false)
        else v[g[i,j]]:=true;

  fillchar(v,sizeof(v),0);             //4
  for i:=4 to 6 do
    for j:=1 to 3 do
      if v[g[i,j]] then exit(false)
        else v[g[i,j]]:=true;

  fillchar(v,sizeof(v),0);             //5
  for i:=4 to 6 do
    for j:=4 to 6 do
      if v[g[i,j]] then exit(false)
        else v[g[i,j]]:=true;

  fillchar(v,sizeof(v),0);             //6
  for i:=4 to 6 do
    for j:=7 to 9 do
      if v[g[i,j]] then exit(false)
        else v[g[i,j]]:=true;

  fillchar(v,sizeof(v),0);             //7
  for i:=7 to 9 do
    for j:=1 to 3 do
      if v[g[i,j]] then exit(false)
        else v[g[i,j]]:=true;

  fillchar(v,sizeof(v),0);             //8
  for i:=7 to 9 do
    for j:=4 to 6 do
      if v[g[i,j]] then exit(false)
        else v[g[i,j]]:=true;

  fillchar(v,sizeof(v),0);             //9
  for i:=7 to 9 do
    for j:=7 to 9 do
      if v[g[i,j]] then exit(false)
        else v[g[i,j]]:=true;

  exit(true);
end;

begin
  read(n);
  for t:=1 to n do
    begin
      for i:=1 to 9 do
        for j:=1 to 9 do read(g[i,j]);
      if check then writeln('Right')
        else writeln('Wrong');
    end;
end.