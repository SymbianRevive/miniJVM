package javax.sound.sampled;

public class AudioSystem {
	public SourceDataLine getSourceDataLine(AudioFormat format) {
		return new SourceDataLine(format, 1024);
	}
}
