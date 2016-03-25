#include <boost/random.hpp>
#include <ctime>
 
using namespace boost;
 
double SampleNormal (double mean, double sigma)
{
    // 建立一个 Mersenne twister 随机数产生器
    // 使用 Unix 时间设定 seed
    static mt19937 rng(static_cast<unsigned> (std::time(0)));
 
    // 选择高斯机率分布
    normal_distribution<double> norm_dist(mean, sigma);
 
    // 使用 function 的形式，生成随机数据产生器
    variate_generator<mt19937&, normal_distribution<double> >  normal_sampler(rng, norm_dist);
 
    // 传回样本分布结果
    return normal_sampler();
}

int main()
{
	std::cout << SampleNormal(5.0,3.0)<<std::endl;	
	return 0;
}
