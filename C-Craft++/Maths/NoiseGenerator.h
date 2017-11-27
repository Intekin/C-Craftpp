#pragma once

struct NoiseParameters
{
	int ocaves;
	int amplitudes;
	int smoothness;
	int heightoffset;

	double roughness;
};

class NoiseGenerator
{
public :
	NoiseGenerator(int seed);
	double getHeight(int x, int z, int chunkX, int chunkZ) const noexcept;
	void setParameters(const NoiseParameters& params) noexcept;

private:
	double getNoise(int n)const noexcept;
	double getNoise(double x, double z) const noexcept;
	double lerp(double a, double b, double z) const noexcept;
	double noise(double x, double z) const noexcept;

	NoiseParameters m_noiseParameters;
	int m_seed;

};