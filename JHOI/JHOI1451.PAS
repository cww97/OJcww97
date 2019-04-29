program cx;
const big=999999999;
      dx:array[1..4]of longint=(0,0,1,-1);
      dy:array[1..4]of longint=(1,-1,0,0);
var i,n,m,ans,j,x,y,ff,rr,xx,yy,p:longint;
    l,r,qx,qy,f:array[0..100000]of longint;
    ar:array[0..100000]of boolean;
    v:array[0..1000,0..1000]of boolean;
    g:array[0..1000,0..1000]of longint;

function min(x,y:longint):longint;
begin
  if x>y then exit(y);
  exit(x);
end;

function max(x,y:longint):longint;
begin
  if x>y then exit(x);
  exit(y);
end;

begin
  read(m,n);
  for i:=1 to m do
    for j:=1 to n do read(g[i,j]);
  fillchar(ar,sizeof(ar),0);
  fillchar(l,sizeof(l),63);
  for i:=1 to n do r[i]:=-big;
  fillchar(qx,sizeof(qx),0);
  fillchar(qy,sizeof(qy),0);
  v[1,1]:= false;

  for p:=1 to n do
    if v[1,p]=false then
    begin
      fillchar(v,sizeof(v),0);
      ff:=1;
      rr:=1;
      qx[1]:=1;
      qy[1]:=p;
      while ff<=rr do
        begin
          x:=qx[ff];
          y:=qy[ff];
          if x=m then
            begin
              l[p]:=min(l[p],y);
              r[p]:=max(r[p],y);
              ar[y]:=true;
            end;
          for i:=1 to 4 do
            begin
              xx:=x+dx[i];
              yy:=y+dy[i];
              if (xx<=0)or(xx>m)or(yy<=0)or(yy>n) then continue;
              if v[xx,yy] then continue;
              if g[xx,yy]>=g[x,y] then continue;
              inc(rr);
              qx[rr]:=xx;
              qy[rr]:=yy;
              v[xx,yy]:=true;
            end;
          inc(ff);
        end;
      end;
  
for i:=1 to n do if not ar[i] then inc(ans);
  if ans<>0 then
    begin
      writeln(0);
      writeln(ans);
    end
  else
    begin
      fillchar(f,sizeof(f),63);
      f[0]:=0;
      for i:=1 to n do
        for j:=l[i] to r[i] do
          f[j]:=min(f[j],f[l[i]-1]+1);
      writeln(1);
      writeln(f[n]);
    end;
end.