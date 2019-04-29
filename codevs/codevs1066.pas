program cx;
uses math;
const dx:array[1..4]of longint=(-1,0,1,0);
      dy:array[1..4]of longint=(0,-1,0,1);
var i,j,n,m,ff,rr,bx,by,x,y,ans:longint;
    v:array[0..600,0..600]of boolean;
    ar:array[0..600]of boolean;
    f,l,r:array[0..600]of longint;
    g:array[0..600,0..600]of longint;
    qx,qy:array[0..1000000]of longint;

procedure bfs(p:longint);
var i:longint;
begin
  if v[1,p] then exit;
  fillchar(v,sizeof(v),0);
  for i:=0 to m+1 do begin v[i,0]:=true; v[i,n+1]:=true; end;
  for i:=0 to n+1 do begin v[0,i]:=true; v[m+1,i]:=true; end;
  ff:=1; rr:=1;
  qx[1]:=1; qy[1]:=p;
  while ff<=rr do
    begin
      x:=qx[ff]; y:=qy[ff];
      if x=m then
        begin
          l[p]:=min(l[p],y);
          r[p]:=max(r[p],y);
          ar[y]:=true;
        end;
      for i:=1 to 4 do
        begin
          bx:=x+dx[i]; by:=y+dy[i];
          if g[bx,by]>=g[x,y] then continue;
          if v[bx,by] then continue;
          v[bx,by]:=true;
          inc(rr); qx[rr]:=bx; qy[rr]:=by;
        end;
      inc(ff);
    end;
end;

begin
  read(m,n);
  for i:=1 to m do
    for j:=1 to n do read(g[i,j]);
  fillchar(l,sizeof(l),63);
  for i:=1 to n do r[i]:=-99999999;

  for i:=1 to n do bfs(i);
  for i:=1 to n do
    if not ar[i] then inc(ans);
  if ans>0 then
    begin writeln(0); writeln(ans); end
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
