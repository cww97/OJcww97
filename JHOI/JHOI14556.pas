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

procedure bfs(x:longint);
var i,f,r,t:longint;
    hk:boolean;
begin
  fillchar(d,sizeof(d),0);
  if not v[x] then dec(left);
  f:=1;
  r:=1;
  q[1]:=x;
  v[x]:=true;
  d[x]:=0;
  while f<=r do
    begin
      t:=head[q[f]];
      while t>0 do
        begin
          hk:=false;
          if (d[q[f]]+w[t]<sd[e[t]]) and
             (sd[e[t]]<>big)then hk:=true;
          d[e[t]]:=d[q[f]]+w[t];
          sd[e[t]]:=min(sd[e[t]],d[e[t]]);
          if d[e[t]]>=k then begin t:=next[t]; continue; end;
          if v[e[t]] and not hk then begin t:=next[t]; continue; end;
          inc(r);
          if not v[e[t]] then dec(left);
          v[e[t]]:=true;
          q[r]:=e[t];
          t:=next[t];
        end;
      inc(f);
    end;
end;

begin
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
      bfs(x);
      writeln(left);
    end;
end.
