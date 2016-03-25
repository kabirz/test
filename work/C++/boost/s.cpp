#include <boost/random.hpp>
#include <ctime>
 
using namespace boost;
 
double SampleNormal (double mean, double sigma)
{
    // ����һ�� Mersenne twister �����������
    // ʹ�� Unix ʱ���趨 seed
    static mt19937 rng(static_cast<unsigned> (std::time(0)));
 
    // ѡ���˹���ʷֲ�
    normal_distribution<double> norm_dist(mean, sigma);
 
    // ʹ�� function ����ʽ������������ݲ�����
    variate_generator<mt19937&, normal_distribution<double> >  normal_sampler(rng, norm_dist);
 
    // ���������ֲ����
    return normal_sampler();
}

int main()
{
	std::cout << SampleNormal(5.0,3.0)<<std::endl;	
	return 0;
}
