static int self_collision(blaze::StaticVector<float,8>& ax, blaze::StaticVector<float,8>& ay, blaze::StaticVector<float,8>& az, float ar,
std::vector<blaze::StaticVector<float,8>>& bx, std::vector<blaze::StaticVector<float,8>>& by, std::vector<blaze::StaticVector<float,8>>& bz, std::vector<float>& br,
std::vector<blaze::StaticVector<float,8>>& dx, std::vector<blaze::StaticVector<float,8>>& dy, std::vector<blaze::StaticVector<float,8>>& dz, std::vector<float>& dr,
std::vector<std::vector<blaze::StaticVector<float,8>>>& sx, std::vector<std::vector<blaze::StaticVector<float,8>>>& sy, std::vector<std::vector<blaze::StaticVector<float,8>>>& sz, std::vector<std::vector<float>>& sr){
  int res=false;
  for(size_t l=0;l<dx.size();l=l+1){
    blaze::StaticVector<float,8> xs = (ax - dx[l]);
    blaze::StaticVector<float,8> ys = (ay - dy[l]);
    blaze::StaticVector<float,8> zs = (az - dz[l]);

    blaze::StaticVector<float,8> sum= xs*xs+ys*ys+zs*zs;
    float rs = ar + dr[l];

    sum = sum - rs*rs;

    res=(blaze::min(sum) < 0.0);

    if(res){
      if(bx.size() == 0 and (sx[l]).size() == 0 ){
        return 1;
      }
      else if(bx.size() == 0){
        for(size_t j=0;j<(sx[l]).size();j=j+1){
          xs = (ax - (sx[l])[j]);
          ys = (ay - (sy[l])[j]);
          zs = (az - (sz[l])[j]);

          sum= xs*xs+ys*ys+zs*zs;
          rs = ar + (sr[l])[j];

          sum = sum - rs*rs;

          if(blaze::min(sum)<0.0){
            return true;
          }
        }
      }
      else if((sx[l]).size() == 0 ){
        for(size_t i=0;i<bx.size();i=i+1){
          xs = (bx[i] - dx[l]);
          ys = (by[i] - dy[l]);
          zs = (bz[i] - dz[l]);

          sum= xs*xs+ys*ys+zs*zs;
          rs = br[i] + dr[l];

          sum = sum - rs*rs;

          if(blaze::min(sum)<0.0){
            return true;
          }
        }
      }
      else{
        for(size_t j=0;j<(sx[l]).size();j=j+1){
          for(size_t i=0;i<bx.size();i=i+1){
            xs = (bx[i] - (sx[l])[j]);
            ys = (by[i] - (sy[l])[j]);
            zs = (bz[i] - (sz[l])[j]);

            sum= xs*xs+ys*ys+zs*zs;
            rs = br[i] + (sr[l])[j];

            sum = sum - rs*rs;

            if(blaze::min(sum)<0.0) return true;
          }
        }
      }
      res=false;
    }
  }
  return false;
}