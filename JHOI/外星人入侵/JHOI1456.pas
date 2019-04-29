program cx;
uses math;
//const big=1061109567;
var i,n,m,a,k,x,y,z,cnt,left:longint;
    e,w,head,next,d,q,sd:array[0..100]of longint;
    v,con:array[0..100]of boolean;

procedure build(x,y,z:longint);
begin
  inc(cnt);
  e[cnt]:=y;
  w[cnt]:=z;
  next[cnt]:=head[x];
  head[x]:=cnt;
end;

procedure spfa(p:longint);
var i,hk,f,r,t:longint;
begin
  fillchar(v,sizeof(v),0);
  for i:=1 to n do d[i]:=k;
  d[p]:=0;
  f:=1; r:=1; q[1]:=p; v[p]:=true;
  if not con[p] then begin dec(left); con[p]:=true; end;
  while f<=r do
    begin
      t:=head[q[f]];
      while t>0 do
        begin
          if d[q[f]]+w[t]<d[e[t]] then
            begin
              if not con[e[t]] then begin dec(left); con[e[t]]:=true; end;
              d[e[t]]:=d[q[f]]+w[t];
              if sd[e[t]]<=d[e[t]] then begin t:=next[t]; continue; end;
              sd[e[t]]:=d[e[t]];
              if not v[e[t]] then
                begin
                  inc(r);
                  q[r]:=e[t];
                  v[e[t]]:=true;
                end;
            end;
          t:=next[t];
        end;
      v[q[f]]:=false;
      inc(f);
    end;
end;

begin
  fillchar(sd,sizeof(sd),63);
  read(n,m,a,k);
  for i:=1 to m do
    begin
      read(x,y,z);
      build(x,y,z);
      build(y,x,z);
    end;

  left:=n;
  for i:=1 to a do
    begin
      read(x);
      spfa(x);
      writeln(left);
    end;
end.
