program cx;
uses math;
const big=1061109567;
var i,n,m,a,k,x,y,z,cnt,left:longint;
    e,w,head,next,d,q,sd:array[0..100]of longint;
    v:array[0..100]of boolean;

procedure build(x,y,z:longint);
begin
  inc(cnt);
  e[cnt]:=y;
  w[cnt]:=z;
  next[cnt]:=head[x];
  head[x]:=cnt;
end;

procedure dfs(t,d:longint);
var i,hk:longint;
begin
  if d>k then exit;
  if v[t] and (d>=sd[t]) then exit;
  if v[t] and (d<sd[t]) then
    begin
      sd[t]:=d;
      hk:=head[t];
      while hk>0 do
        begin dfs(e[hk],d+w[t]); hk:=next[hk]; end;
      exit;
    end;
  if not v[t] then
    begin
      sd[t]:=d;
      v[t]:=true;
      dec(left);
      hk:=head[t];
      while hk>0 do
        begin dfs(e[hk],d+w[t]); hk:=next[hk]; end;
    end;

end;

begin
  assign(input,'lzy.in');reset(input);
  fillchar(sd,sizeof(sd),63);
  writeln(sd[1]);
  read(n,m,a,k);
  for i:=1 to m do
    begin
      read(x,y,z);
      build(x,y,z);
      build(y,x,z);
    end;

  left:=n;
  fillchar(v,sizeof(v),0);
  for i:=1 to a do
    begin
      read(x);
      dfs(x,0);
      writeln(left);
    end;
  close(input);
end.
