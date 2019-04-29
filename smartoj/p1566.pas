program cx;
const big=999999999;
      dx:array[1..4]of longint=(0,0,1,-1);
      dy:array[1..4]of longint=(1,-1,0,0);
var i,n,m,ans,j:longint;
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

procedure bfs(x,y:longint);
var i,f,rr,cx,cy:longint;
begin
  fillchar(v,sizeof(v),1);
  for i:=1 to m do
    for j:=1 to n do v[i,j]:=false;
  f:=1;
  rr:=1;
  v[x,y]:=true;
  qx[1]:=x;
  qy[1]:=y;
  while f<=rr do
    begin
      for i:=1 to 4 do
        begin
          cx:=qx[f]+dx[i];
          cy:=qy[f]+dy[i];
          if v[cx,cy] then continue;
          if g[cx,cy]>g[qx[f],qy[f]] then continue;
          if cx=m then
            begin
              l[x]:=min(l[x],cy);
              r[x]:=max(r[x],cy);
              ar[cy]:=true;
            end;
          inc(rr);
          qx[rr]:=cx;
          qy[rr]:=cy;
          v[cx,cy]:=true;
        end;
      inc(f);
    end;
end;

begin
  assign(input,'flow.in');  reset(input);
  //assign(output,'flow.out');rewrite(output);
  read(m,n);
  for i:=1 to m do
    for j:=1 to n do read(g[i,j]);
  fillchar(ar,sizeof(ar),0);
  fillchar(l,sizeof(l),63);
  for i:=1 to n do r[i]:=-big;
  for i:=1 to n do bfs(1,i);

  for i:=1 to n do if not ar[i] then inc(ans);
  if ans<>0 then
    begin
      writeln(0);
      writeln(ans);
    end
  else
    begin
      fillchar(f,sizeof(f),63);
      for i:=1 to n do
        for j:=l[i] to r[i] do
          f[j]:=min(f[j],f[l[i]-1]+1);
      writeln(f[n])
    end;
  close(input);
  //close(output);
end.
