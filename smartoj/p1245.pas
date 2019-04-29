program cx;  //·ÖÌÇ¹û
var g:array[0..1000,0..1000]of integer;
    v:array[0..1000000]of boolean;
    a:array[0..1000000]of longint;
    sum,n,m,p,time,c,i,x,y,f,r:longint;
    ok:boolean;

begin
  fillchar(g,sizeof(g),0);
  fillchar(v,sizeof(v),0);
  read(n,p,c,m);
  for i:=1 to p do
    begin
      read(x,y);
      g[x,y]:=1;
      g[y,x]:=1;
    end;

  a[1]:=c;
  v[c]:=true;
  f:=1;
  r:=1;
  time:=1;
  ok:=false;

  repeat
    for i:=1 to n do
      begin
        if v[i] then continue;
        if g[a[f],i]=0 then continue;
        inc(r);
        a[r]:=i;
        v[i]:=true;
        ok:=true;
      end;
    if ok then inc(time);
    ok:=false;
    inc(f);
  until f>r;
  writeln(time+m);
end.
