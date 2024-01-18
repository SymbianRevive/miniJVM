package javax.sound.sampled;

public class AudioFormat {
	float sampleRate;
	int sampleSizeInBits;
	int channels;
	boolean signed;
	boolean bigEndian;

	public AudioFormat(float sampleRate, int sampleSizeInBits, int channels, boolean signed, boolean bigEndian) {
		this.sampleRate = sampleRate;
		this.sampleSizeInBits = sampleSizeInBits;
		this.channels = channels;
		this.signed = signed;
		this.bigEndian = bigEndian;
	}
}
